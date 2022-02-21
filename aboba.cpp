//
// Created by sage on 17.02.2022.
//

#include "aboba.h"

const std::map<char, int> Shinobi::ranks = {
		{'D', 5},
		{'C', 4},
		{'B', 3},
		{'A', 2},
		{'S', 1}
};

const std::map<int, char> Shinobi::rank_numbers = {
		{5, 'D'},
		{4, 'C'},
		{3, 'B'},
		{2, 'A'},
		{1, 'S'}
};


// конструктор по умолчанию
// создаёт слабого шиноби странника
Shinobi::Shinobi() {
	this->rank = 'D';
	this->abilities = 3;
	this->speed = 10;
	this->is_rogue = false;
	this->clan = "Wanderer";
	this->rank_number = 5;
}

// конструктор через ранг как символ, и все остальные параметры

Shinobi::Shinobi(char rank, int abilities, float speed, bool is_rogue, std::string clan) {
	this->rank = rank;
	this->abilities = abilities;
	this->speed = speed;
	this->is_rogue = is_rogue;
	this->clan = clan;
	this->rank_number = this->ranks.at(this->rank);
}


// конструктор копирования
Shinobi::Shinobi(const Shinobi &other) {
	this->rank = other.rank;
	this->abilities = other.abilities;
	this->speed = other.speed;
	this->is_rogue = other.is_rogue;
	this->clan = other.clan;
	this->rank_number = other.rank_number;
}


// сложение ведёт к объединению в пару-отряд
std::pair<Shinobi, Shinobi> Shinobi::operator+(Shinobi other) {
	return std::pair<Shinobi, Shinobi>(*this, other);
}


Shinobi::~Shinobi() {
}

// взаимодействие между двумя шиноби
// вернёт самого себя при приветствии
// если оба находятся по разные стороны закона - начнётся бой
// при бое, вернёт сильнейшего
Shinobi &Shinobi::interact(Shinobi &other) {
	if (this->is_rogue == other.is_rogue) {
		if (this->is_rogue) {
			printf("Hey there, fellow criminal\n");
		} else {
			if (other.clan == "Wanderer") {
				printf("May your path be clear, stranger\n");
				return *this;
			} else if (this->clan == other.clan) {
				printf("Suprised to see you far from home, my friend from %s clan!\n", this->clan.c_str());
				return *this;
			} else {
				printf("Hey there, ninja from %s clan!", this->clan.c_str());
				return *this;
			}
		}
	}
	return fight(other);
}

// покинуть клан, став странником
void Shinobi::leave_clan() {
	printf("Some day i might come back, my friends from %s clan\n", this->clan.c_str());
	this->clan = "Wanderer";
}

// метод боя вернёт сильнейшего из двух
// победитель добавляет техники врага к своим и получает повышение ранга
Shinobi &Shinobi::fight(Shinobi &other) {
	if (this->is_rogue) {
		printf("Never should have left your village!\n");
		if ((*this) > other) {
			printf("Should have escaped when you had the chane!\n");
			this->setAbilities((this->abilities) + other.abilities);
			this->rank_raise();
			return *this;
		}
		printf("So this is how criminals die, always alone..\n");
		return other;
		
	}
	printf("I'm not affraid, you criminal scum!\n");
	if ((*this) > other) {
		printf("Justice is finally restored\n");
		this->setAbilities((this->abilities) + other.abilities);
		this->rank_raise();
		return *this;
	}
	if (this->clan == "Wanderer") {
		printf("So this is how strangers die, on a forst road..\n");
		return other;
	}
	printf("My people from %s clan will avenge me\n", this->clan.c_str());
	return other;
}

// устанавливает клан
void Shinobi::setClan(std::string &clan) {
	this->clan = clan;
}

// сравнивает ниндзя по силе
bool Shinobi::operator>(Shinobi &other) {
	if (this->rank_number == other.rank_number) {
		if (this->abilities == other.abilities) {
			return (this->speed > other.speed);
		}
		return this->abilities > other.abilities;
	}
	return this->rank_number > other.rank_number;
}

bool Shinobi::operator<(Shinobi &other) {
	if (this->rank_number == other.rank_number) {
		if (this->abilities == other.abilities) {
			return (this->speed < other.speed);
		}
		return this->abilities < other.abilities;
	}
	return this->rank_number < other.rank_number;
}

bool Shinobi::operator==(Shinobi &other) {
	return (this->rank_number == other.rank_number) && (this->speed == other.speed) &&
	       (this->abilities == other.abilities);
}

void Shinobi::rank_raise() {
	if (this->rank_number == 1) {
		return;
	}
	++this->rank_number;
	this->rank = this->rank_numbers.at(this->rank_number);
}

void Shinobi::setAbilities(int abilities) {
	if (abilities < 0) {
		printf("Error, amount of abilities can't be negative number\n");
		return;
	}
	this->abilities = abilities;
	return;
}

void Shinobi::setRank(int &rank_number) {
	if (rank_number < 1 || rank_number > 5) {
		printf("Error, rank number out of range\n");
		return;
	}
	this->rank_number = rank_number;
	this->rank = this->rank_numbers.at(this->rank_number);
	return;
}

void Shinobi::setRank(char &rank_name) {
	if (std::string("SABCD").find(rank_name) == -1) {
		printf("Error, invalid rank name\n");
		return;
	}
	this->rank = rank_name;
	this->rank_number = this->ranks.at(rank_name);
	return;
	
}

void Shinobi::go_exile() {
	if (this->is_rogue) {
		printf("Nice try, but you can't be banished twice\n");
		return;
	} else if (this->clan != "Wanderer") printf("I'll miss you, my fellows from %s clan", this->clan.c_str());
	this->is_rogue = true;
	return;
}

void operator<<(std::ostream &ostr, Shinobi &shino) {
	ostr << "I am " << shino.rank << " rank ninja ";
	if (shino.is_rogue) ostr << "in banishment";
	else if (shino.clan != "Wanderer") ostr << "from " << shino.clan << " clan";
	ostr << '\n';
	ostr << "i know " << shino.abilities << " techniques\n";
	return;
}

void Shinobi::suspect(std::ostream &ostr) {
	ostr << "A shinobi is nearby..\n";
	return;
}

Shinobi::Shinobi(char rank, int abilities, float speed, bool is_rogue) {
	
	this->rank = rank;
	this->abilities = abilities;
	this->speed = speed;
	this->is_rogue = is_rogue;
	this->clan = "Wanderer";
	this->rank_number = this->ranks.at(rank);
}

Shinobi::Shinobi(int rank_number, int abilities, float speed, bool is_rogue, std::string clan) {
	
	this->rank_number = rank_number;
	this->abilities = abilities;
	this->speed = speed;
	this->is_rogue = is_rogue;
	this->clan = clan;
	this->rank = this->rank_numbers.at(rank_number);
}

Shinobi::Shinobi(int rank_number, int abilities, float speed, bool is_rogue) {
	this->rank_number = rank_number;
	this->abilities = abilities;
	this->speed = speed;
	this->is_rogue = is_rogue;
	this->clan = "Wanderer";
	this->rank = this->rank_numbers.at(rank_number);
	
}

