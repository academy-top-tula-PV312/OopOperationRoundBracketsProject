#include <iostream>
#include <string>

class User
{
	std::string name;
	int age;
public:
	User() : User("", 0){}
	User(std::string name, int age)
		: name{ name }, age{ age } {};
	
	std::string& Name() { return name; }
	int& Age() { return age; }

	std::string ToString()
	{
		return "Name: " + name + ", Age: " + std::to_string(age);
	}
};

class UserAgeComparer
{
public:
	bool operator()(int age1, int age2)
	{
		return age1 < age2;
	}
};

class Group
{
	User* users;
	int size;

public:
	Group() : users{ nullptr }, size{} {}
	void Add(User user)
	{
		User* usersNew = new User[size + 1];
		for (int i{}; i < size; i++)
			usersNew[i] = users[i];
		usersNew[size] = user;
		users = usersNew;
		size++;
	}

	User& operator[](int index) { return users[index]; }

	int Size() { return size; }

	void Sort()
	{
		for (int i{}; i < size; i++)
			for (int j{ size - 1 }; j > i; j--)
				if (users[j].Name() < users[j - 1].Name())
					std::swap(users[j], users[j - 1]);
	}

	void Sort(UserAgeComparer comparer)
	{
		for (int i{}; i < size; i++)
			for (int j{ size - 1 }; j > i; j--)
				if (comparer(users[j].Age(), users[j - 1].Age()))
					std::swap(users[j], users[j - 1]);
	}
};


int main()
{
	Group group;
	group.Add(User("Sammy", 25));
	group.Add(User("Jimmy", 19));
	group.Add(User("Tommy", 42));
	group.Add(User("Billy", 36));

	for (int i{}; i < group.Size(); i++)
		std::cout << group[i].ToString() << "\n";
	std::cout << "\n";
	group.Sort();

	for (int i{}; i < group.Size(); i++)
		std::cout << group[i].ToString() << "\n";
	std::cout << "\n";

	group.Sort(UserAgeComparer());
	for (int i{}; i < group.Size(); i++)
		std::cout << group[i].ToString() << "\n";
	std::cout << "\n";
}