#pragma once


struct APipeComponent;
struct IPipe {
	virtual ~IPipe() { }
	virtual const APipeComponent* GetComponent(int x, int y) const = 0;
	virtual bool IsPipeValid() const = 0;
};
struct APipeComponent {
	virtual ~APipeComponent() { }
	virtual bool IsConnectionValid(const IPipe* pipe) const = 0;
	int _x;
	int _y;
};
