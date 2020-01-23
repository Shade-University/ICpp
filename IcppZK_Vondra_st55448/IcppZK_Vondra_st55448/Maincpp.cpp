#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Node.h"

/* Pomocn� metoda k p�epo�tu hashe */
int aSum(std::string string)
{
	int sum = 0;
	for (int i = 0; i < string.length(); i++)
	{
		sum += string[i];
	}
	return sum;
}

/* Metoda p�epo��t� hash */
bool checkHash(std::string hash, std::string data, std::string key, std::string parentKey, std::string parentHash)
{
	int hashInt = std::stoi(hash);
	int output = 0x66 + aSum(data) + aSum(key) + aSum(parentKey) + aSum(parentHash);

	return hashInt == output;
}

/* Metoda zkontroluje, jestli u� jsme tento kl�� zpracovali */
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

/* Hlavni metoda na na�ten� bloku */
Node* loadNode(std::string key, std::vector<std::string> vContainKeys)
{
	if (checkIfKeyAlreadyContained(key, vContainKeys))
	{
		return nullptr;
	} //Prvn� zkontrolujeme, jestli u� jsme tento blok nezpracov�vali

	vContainKeys.push_back(key);
	std::ifstream file("data/" + key);

	if (!file.is_open())
	{
		return nullptr;
	} //Pokud jsme nena�li dan� soubor

	std::string data, loadedHash, parentKey;
	file >> data >> loadedHash >> parentKey; //Na�ti �daje ze souboru
	file.close();

	Node* parentNode;
	if (!key._Equal(parentKey)) //Pokud jsme dos�hli konce (kl�� se rovn� sob� samotn�mu, ukon�i
	{
		parentNode = loadNode(parentKey, vContainKeys); //Rekurzivn� na�ti parent blok

		if (parentNode != nullptr && !checkHash(loadedHash, data, key, parentKey, parentNode->hash)) //Pokud se hash nerovn�, ukon�i �et�zec
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

	return node; //Vytvo� nodu a vra�
}

Node* loadNode(std::string key)
{
	std::vector<std::string> vector;
	return loadNode(key, vector);
}

/*Metoda projede ulo�en� �et�zce a vr�t� blok za��tku nejdel��ho */
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
	indexFile >> keyCount; //Na�ti po�et blok�

	Node** nodes = new Node*[keyCount];

	std::cout << "Nacitam chainy [" << keyCount <<"] ..." << std::endl;
	for (int i = 0; i < keyCount; i++)
	{
		std::string key;
		indexFile >> key; //p�e�ti kl�� bloku

		Node* node = loadNode(key); //Na�ti cel� chain
		nodes[i] = node; //ulo� chain
	} //Na�ti chain a ulo� do pole;

	std::cout << "Chainy nacteny [" << keyCount << "]" << std::endl;
	std::cout << "Hled�m nejdelsi chain.." << std::endl;
	Node* maxChain = findMaxChain(nodes, keyCount); //Vra� max. chain

	
	std::cout << "Nejdelsi chain zacina blokem s klicem: " << maxChain->key << std::endl; //Vypi� kl�� prvn�ho bloku v nejdel��m chainu
	
	indexFile.close();
	clearMemory(nodes, keyCount);

	std::cin.get();
}