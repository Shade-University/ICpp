#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Node.h"

/* Pomocná metoda k pøepoètu hashe */
int aSum(std::string string)
{
	int sum = 0;
	for (int i = 0; i < string.length(); i++)
	{
		sum += string[i];
	}
	return sum;
}

/* Metoda pøepoèítá hash */
bool checkHash(std::string hash, std::string data, std::string key, std::string parentKey, std::string parentHash)
{
	int hashInt = std::stoi(hash);
	int output = 0x66 + aSum(data) + aSum(key) + aSum(parentKey) + aSum(parentHash);

	return hashInt == output;
}

/* Metoda zkontroluje, jestli u jsme tento klíè zpracovali */
bool checkIfKeyAlreadyContained(std::string key, std::vector<std::string> vContainKeys)
{
	bool keyAlreadyContained = false;
	for (int i = 0; i < vContainKeys.size(); i++)
	{
		if (vContainKeys[i]._Equal(key))
			keyAlreadyContained = true;
	}
	return keyAlreadyContained;
}

/* Hlavni metoda na naètení bloku */
Node* loadNode(std::string key, std::vector<std::string> vContainKeys)
{
	if (checkIfKeyAlreadyContained(key, vContainKeys))
	{
		return nullptr;
	} //Prvnì zkontrolujeme, jestli u jsme tento blok nezpracovávali

	vContainKeys.push_back(key);
	std::ifstream file("data/" + key);

	if (!file.is_open())
	{
		return nullptr;
	} //Pokud jsme nenašli danı soubor

	std::string data, loadedHash, parentKey;
	file >> data >> loadedHash >> parentKey; //Naèti údaje ze souboru
	file.close();

	Node* parentNode;
	if (!key._Equal(parentKey)) //Pokud jsme dosáhli konce (klíè se rovná sobì samotnımu, ukonèi
	{
		parentNode = loadNode(parentKey, vContainKeys); //Rekurzivnì naèti parent blok

		if (parentNode != nullptr && !checkHash(loadedHash, data, key, parentKey, parentNode->hash)) //Pokud se hash nerovná, ukonèi øetìzec
		{
			parentNode = nullptr;
		}
	}
	else
	{
		parentNode = nullptr;
	}


	Node* node = new Node();
	node->key = key;
	node->data = data;
	node->hash = loadedHash;
	node->parent = parentNode;

	return node; //Vytvoø nodu a vra
}

Node* loadNode(std::string key)
{
	std::vector<std::string> vector;
	return loadNode(key, vector);
}

/*Metoda projede uloené øetìzce a vrátí blok zaèátku nejdelšího */
Node* findMaxChain(Node** nodes, int count)
{
	int max = 0;
	int maxI = 0;

	for (int i = 0; i < count; i++)
	{
		int counter = 0;
		Node* node = nodes[i];
		while (node->parent != nullptr)
		{
			node = node->parent;
			counter++;
		}
		
		std::cout << nodes[i]->key << "->" << counter << std::endl;

		if (counter > max)
		{
			max = counter;
			maxI = i;
		}
	}

	return nodes[maxI];
}

void clearMemory(Node** nodes, int count)
{
	
	for (int i = 0; i < count; i++)
	{
		Node* temp = nodes[i];
		while (temp->parent != nullptr)
		{
			Node* parent = temp->parent;
			delete temp;
			temp = parent;
		}
		delete temp;
	}
	delete[] nodes;
}

int main()
{
	std::ifstream indexFile("data/index");

	int keyCount;
	indexFile >> keyCount; //Naèti poèet blokù

	Node** nodes = new Node*[keyCount];

	std::cout << "Nacitam chainy [" << keyCount <<"] ..." << std::endl;
	for (int i = 0; i < keyCount; i++)
	{
		std::string key;
		indexFile >> key; //pøeèti klíè bloku

		Node* node = loadNode(key); //Naèti celı chain
		nodes[i] = node; //ulo chain
	} //Naèti chain a ulo do pole;

	std::cout << "Chainy nacteny [" << keyCount << "]" << std::endl;
	std::cout << "Hledám nejdelsi chain.." << std::endl;
	Node* maxChain = findMaxChain(nodes, keyCount); //Vra max. chain

	
	std::cout << "Nejdelsi chain zacina blokem s klicem: " << maxChain->key << std::endl; //Vypiš klíè prvního bloku v nejdelším chainu
	
	indexFile.close();
	clearMemory(nodes, keyCount);

	std::cin.get();
}