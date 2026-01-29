#include <iostream>
using namespace std;


void afisare_tabla(char  tabla[4][4]) {
	for (int i = 1; i <= 3; i++)
	{
		cout << "---------" << endl;
		for (int j = 1; j <= 3; j++)
		{
			cout << "|" << tabla[i][j] << "|";
		}
		cout << endl;
	}

}

void afis_scor(int x, int y) {
	cout << "scor x=" << x << endl;
	cout << "scor 0=" << y << endl;

}

char verificare_castig(char tb[4][4], char jc1, char jc2,char castigator) {
	
	for (int i = 1; i < 4; i++) {

		if (((tb[1][i] == jc1 || tb[1][i] == jc2) && (tb[1][i] == tb[2][i] && tb[3][i] == tb[1][i])))
			castigator = tb[1][i];
		if (((tb[1][i] == jc1 || tb[1][i] == jc2) && (tb[i][1] == tb[i][2] && tb[i][1] == tb[i][3])))
			castigator = tb[i][1];


	}

	if (((tb[1][1] == jc1 || tb[1][1] == jc2) && (tb[1][1] == tb[2][2] && tb[1][1] == tb[3][3])))
		castigator = tb[1][1];
	else if (((tb[1][3] == jc1 || tb[1][3] == jc2) && (tb[1][3] == tb[2][2] && tb[1][3] == tb[3][1])))
		castigator = tb[1][3];

	return castigator;
}

bool verificare_remiza(char tb[4][4]) {
	int contor = 0;
	bool remiza=false;
	for(int i=1;i<4;i++)
		for (int j = 1; j < 4; j++)
		{
			if (tb[i][j]!='*')
				contor++;
		}
	if (contor == 9)
		remiza = true;
	return	remiza;
}

void start(char tb[4][4], char jucator1, char jucator2, int sx, int s0) {
	cout << "jucatorul 1=x " << "scor=" << sx << endl;
	cout << "jucatorul 2=0 " << "scor=" << s0 << endl;
	string raspunsjcoc;
	bool rem;
	char raspunscastigator=NULL;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			tb[i][j] = '*';
	int r, c;
	afisare_tabla(tb);
	while (true) {
		
		cout << "randul: ";
		cin >> r;
		cout << "coloana: ";
		cin >> c;
		
		if (tb[r][c] != '*') {

			cout << "casuta aleasa este ocupata" << endl;
			cout << "alegeti alta casuta" << endl;

			cout << "randul: ";
			cin >> r;
			cout << "coloana: ";
			cin >> c;

		}
		cout << "simbolul tau:";
		cin >> tb[r][c];
		cout << "\n\n\n\n\n";
		
			
		afisare_tabla(tb);
		
				
		raspunscastigator = verificare_castig(tb, jucator1, jucator2, raspunscastigator);
			
		rem=verificare_remiza(tb);
		if (rem == true)
		{
			cout << "\n\n\este remiz!\n";
			break;
		}

				if (raspunscastigator == jucator1)	{
						sx++;
						cout << "\n\njucatorul 1 a castigat!\n\n";
						break;
					}
				
				if (raspunscastigator == jucator2)	{
						s0++;
						cout << "\n\njucatorul 2 a castigat!\n\n";
						break;
					}



	} 

	cout<<"\n\nvreti sa mai jucati? tastati da sau nu" << endl;
	cin >> raspunsjcoc;

	if (raspunsjcoc == "da")
		start(tb, jucator1, jucator2, sx, s0);

}


int main() {
	char tab[4][4];
	char jc1 = 'x', jc2 = '0';
	int sx = 0, s0 = 0;
	


	start(tab, jc1, jc2, sx, s0);

	return 0;
}
