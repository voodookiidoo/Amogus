//
// Created by sage on 17.02.2022.
//

#ifndef CMAKE_TEST_ABOBA_H
#define CMAKE_TEST_ABOBA_H

#include "string"
#include "iostream"
#include "map"

class Shinobi {
private:
	static const std::map<char, int> ranks; // мапы для преобразования буквенного именования ранга
	static const std::map<int, char> rank_numbers; // в числовой и наоборот
	char rank; // ранг силы в виде символа D-S
	int abilities; // количество техник
	float speed; // скорость
	bool is_rogue; // статус отступника
	int rank_number; // ранг силы в виде числа, 1 - максимальный, 5 - минимальный
	std::string clan; // название клана
	
	Shinobi &fight(Shinobi &other);

public:
	// выводит сообщение о предчувствии ниндзя
	static void suspect(std::ostream &ostr);
	
	// создаёт экземпляр класса со значениями по умолчанию
	Shinobi();
	
	// перегружает оператор сдвига в поток вывода, для передачи главной информации
	friend void operator<<(std::ostream &ostr, Shinobi &shino);
	
	// конструктор принимающий ранг символом и все остальные параметры
	Shinobi(char rank, int abilities, float speed, bool is_rogue, std::string clan);
	
	// констуктор принимающий ранг символом, и все параметры кроме клана
	Shinobi(char rank, int abilities, float speed, bool is_rogue);
	// конструктор принимающий ранг числом, и все остальные параметры
	Shinobi(int rank_number, int abilities, float speed, bool is_rogue, std::string clan);
	// конструктор принимающий ранг числом, и все параметры кроме клана
	Shinobi(int rank_number, int abilities, float speed, bool is_rogue);
	// конструктор копирования
	Shinobi(const Shinobi &other);
	
	// складывает двух ниндзя в парный отряд
	std::pair<Shinobi, Shinobi> operator+(Shinobi other);
	
	// уходит в изгнание, нарекаясь отступником
	void go_exile();
	
	// операторы сравнения, сравнивают двух ниндзя по силе
	bool operator>(Shinobi &other);
	
	bool operator<(Shinobi &other);
	
	bool operator==(Shinobi &other);
	
	// добровольно покидает клан, нарекаясь странником
	void leave_clan();
	
	// устанавливает новый клан
	void setClan(std::string &clan);
	
	// повышение до следующего ранга
	void rank_raise();
	
	// установить количество техник
	void setAbilities(int abilities);
	
	// установить ранг через число
	void setRank(int &rank_number);
	
	// установить ранг через символ
	void setRank(char &rank_name);
	
	// запустить сценарий взаимодействия между двумя ниндзя
	Shinobi &interact(Shinobi &other);
	
	
	~Shinobi();
};


#endif //CMAKE_TEST_ABOBA_H
