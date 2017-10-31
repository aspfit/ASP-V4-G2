#include <iostream>
#define MAXN 20
using namespace std;

class PriorityQueue {
	enum VrstaOdnosa {BezDjece, SamoLijevo, DesnoLijevo};
	int insideArray[MAXN];
	int lastElement;

	VrstaOdnosa PronadiOdnos(int tempIndex) {
		if (tempIndex * 2 + 1 < lastElement) return DesnoLijevo;
		else if (tempIndex * 2 < lastElement) return SamoLijevo;
		else return BezDjece;
	}

public:
	PriorityQueue() : lastElement(1) {
		for (int i = 0; i < MAXN; i++)
			insideArray[i] = (-1);
	}

	void Push(int tempInfo) {
		insideArray[lastElement] = tempInfo;
		int tempIndex = lastElement++;
		while (tempIndex != 1)
			if (insideArray[tempIndex / 2] < insideArray[tempIndex]) {
				swap(insideArray[tempIndex / 2], insideArray[tempIndex]);
				tempIndex /= 2;
			}
			else
				break;
	}

	bool IsEmpty() {
		return (lastElement == 1);
	}

	bool Check(int tempIndex) {
		VrstaOdnosa tempOdnos(PronadiOdnos(tempIndex));
		if (BezDjece) return true;
		else if (SamoLijevo) {
			if (insideArray[tempIndex] > insideArray[tempIndex * 2]) return true;
			else return false;
		}
		else {
			if (insideArray[tempIndex] > insideArray[tempIndex * 2] && insideArray[tempIndex] > insideArray[tempIndex * 2 + 1])
				return true;
			else 
				return false;
		}
	}

	int Pop() {
		int tempIndex(1), tempValue(insideArray[1]);
		insideArray[1] = insideArray[--lastElement];
		while (tempIndex < lastElement) {
			if (Check(tempIndex)) break; //ako se ne mozes vise spustiti, pa prekini
			VrstaOdnosa tempOdnos = PronadiOdnos(tempIndex);
			if (tempOdnos == SamoLijevo) { //ako se mozes spustiti na desno dijete samo
				swap(insideArray[tempIndex], insideArray[tempIndex * 2]);
				tempIndex *= 2;
			}
			else if (tempOdnos == DesnoLijevo) { //na desno ili lijevo dijete
				if (insideArray[tempIndex * 2] >= insideArray[tempIndex * 2 + 1]) {
					//cout << "lijevo je vece" << endl;
					swap(insideArray[tempIndex], insideArray[tempIndex * 2]);
					tempIndex *= 2;
				}
				else {
					swap(insideArray[tempIndex], insideArray[tempIndex * 2 + 1]);
					tempIndex = tempIndex * 2 + 1;
				}
			}
			else
				break;
		}
		return tempValue;
	}
	void PrintTree() {
		cout << "      " << insideArray[1] << endl;
		cout << "   " << insideArray[2] << "     " << insideArray[3] << endl;
		cout << " " << insideArray[4] << "    " << insideArray[5] << endl;
	}

};

int main() {
	PriorityQueue p;

	p.Push(4);
	cout << "dodao 4" << endl;
	p.Push(3);
	cout << "dodao 3" << endl;
	p.Push(10);
	cout << "dodao 10" << endl;
	p.Push(11);
	cout << "dodao 11" << endl;
	p.Push(123);
	cout << "dodao 123" << endl;


	p.PrintTree();
	cout << p.Pop() << endl;
	cout << p.Pop() << endl;
	cout << p.Pop() << endl;
	cout << p.Pop() << endl;
	cout << p.Pop() << endl;
	

	return 0;
}
