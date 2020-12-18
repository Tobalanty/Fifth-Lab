#ifndef CINCLEAR
#define CINCLEAR

bool cinClear() {

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Whops, something went wrong. Please, try again.\n";
		return false;
	}

	std::cin.ignore(3277, '\n');
	return true;
}

#endif
