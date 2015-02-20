#ifndef FLOOR_H
#define FLOOR_H


class Floor
{private:

protected:
	unsigned int m_id;
	static unsigned int m_nextId;
public:
	Floor();
	int getId();
};

#endif