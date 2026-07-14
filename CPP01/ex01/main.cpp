#include "Zombie.hpp"

int main(void){
	int N = 5;
	Zombie *horde;
	std::cout << "creating horde of " << N << " Zombies" << std::endl;
	horde = zombieHorde(N, "Manolito");

	for (int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
