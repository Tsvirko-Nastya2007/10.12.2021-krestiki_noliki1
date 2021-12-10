#include <iostream>
using namespace std;

void init_field(char** field, int size);
void print_field(char** field, int size);
void player_turn(char** field, int size);
bool check_win(char** field, int size, char sign);
bool check_draw(char** field, int size);

//---------MAIN---------------

int main() {
	//memory for field
	int size = 3;
	char** field = new char* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
	}
	init_field(field, size);
	while (true) {
		player_turn(field, size);
		print_field(field, size);
		if (check_win(field, size, 'x')) {
			cout << "X win!" << endl;
			break;
		}
		if (check_draw(field, size)) {
				cout << "Draw((" << endl;
				break;
		}
		if (check_win(field, size, 'o')) {
			cout << "O win!" << endl;
			break;
		}
	}
	return 0;
}

//---------FUNCTIONS----------

void init_field(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = ' ';
		}
	}
}
void print_field(char** field, int size) {
	for (int i = 0; i < size; i++) {
		cout << "|---|---|---|" << endl;
		for (int j = 0; j < size; j++) {
			cout << "| " << field[i][j] << ' ';
		}
		cout << '|' << endl;
	}
	cout << "|---|---|---|" << endl;
}
void player_turn(char** field, int size) {
	int row, col;
	char sign;
	do {
		do {
			cout << "Enter row num: " << endl;
			cin >> row;
		} while (row<0 || row>size - 1);
		do {
			cout << "Enter col num: " << endl;
			cin >> col;
		} while (row<0 || row>size - 1);
	} while (field[row][col]!=' ');
	do {
		cout << "Enter char: " << endl;
		cin >> sign;
	} while (sign != 'x' && sign != 'o');
	field[row][col] = sign;
}
bool check_win(char** field, int size, char sign) {
	//str
	if (field[0][0] == sign && field[0][1] == sign && field[0][2] == sign) return true;
	else if (field[1][0] == sign && field[1][1] == sign && field[1][2] == sign) return true;
	else if (field[2][0] == sign && field[2][1] == sign && field[2][2] == sign) return true;
	//kol										 				   				
	else if (field[0][0] == sign && field[1][0] == sign && field[2][0] == sign) return true;
	else if (field[0][1] == sign && field[1][1] == sign && field[2][1] == sign) return true;
	else if (field[0][2] == sign && field[1][2] == sign && field[2][2] == sign) return true;
	//diag									  				 					
	else if (field[0][0] == sign && field[1][1] == sign && field[2][2] == sign) return true;
	else if (field[0][2] == sign && field[1][1] == sign && field[2][0] == sign) return true;
	return false;
}
bool check_draw(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (field[i][j] == ' ')return false;
		}
	}
	return true;
}