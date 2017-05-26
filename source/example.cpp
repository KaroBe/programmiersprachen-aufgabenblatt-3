#include <cstdlib> // std::rand()
#include <vector> // std::vector<>
#include <list> // std::list<>
#include <iostream> // std::cout
#include <iterator> // std::ostream_iterator<>
#include <algorithm> // std::reverse, std::generate

int main()
{
	//legt Vektor mit 10 default erstellten Einträgen vom Typ int an
	std::vector<int> v0(10);

	//schleife über den Vector v0 (von automatisch ergänztem
	//Typ)
	for (auto& v : v0)
	{
		// wird dem Element v im Vector v0 eine zufällige Zahl
		//zugewiesen
		v = std::rand(); // v ist int
	}

	/*
	copy range of elements (inputIterator first, 
	inputIterator last, Output
	Iterator result) -> z.B. last = das n-2 te Element
	in Vector/Array/anderem iterierbarem Container

	von erstem element von v0 zum letzten element von v0
	gibt über sequentielle ausgabe alle elemente in einzelne
	Zeile aus (schreib in std::out einen Umbruch, wenn über
	dich etwas ausgegeben wurde)

	vector::end points to hypothetical element after the
	last element (used for range including last element,
	because functions often do not include it)
	*/
	std::cout << "copy v0";
	std::copy(std::begin(v0), std::end (v0),
				std::ostream_iterator<int>(std::cout, "\n"));

	/*
	legt liste l0 mit der selben Zahl int einträgen wie v0 an,
	also 10 Einträge
	kopiert werte von v0 in l0
	*/
	std::list <int> l0 (v0.size());
	std::copy (std::begin(v0), std::end(v0), std::begin(l0));

	/*
	legt liste l1 an mit den integer-einträgen aus l0,
	schreibe diese in umgekehrter Reihenfolge in l1
	(reverse kehrt die Elemente in range first-last um)
	*/
	std::list <int> l1 (std::begin(l0), std::end(l0));
	std::reverse(std::begin(l1), std::end(l1));
	std::cout << "copy l1 \n";
	/* ausgabe l1 */
	std::copy ( std::begin (l1), std::end (l1),
				std::ostream_iterator<int>(std::cout, "\n"));
	
	/*
	l1.sort() sortiert die liste
	ausgabe der sortierten liste
	*/
	l1.sort ();
	std::cout << "copy l1 sorted \n";
	std::copy (l1.begin(), l1.end(),
				std::ostream_iterator <int>(std::cout, "\n"));
	
	/*
	Assigns the value returned by successive calls to gen()
	to the elements in the range [first,last).
	gen() has no arguments
	-> basically fills the assigned range with values
	generated by gen(), in this case random ints
	vector::rbegin points to last element (reverse beginning)
	-> iterates backwards to vector::rend is equivalent to
	vector::end but for the theoretical element preceding the
	first element in the vector
	ausgeben der Liste
	*/
	std::generate(std::begin(v0), std::end(v0),std::rand);
	std::cout << "generate stuff \n";
	std::copy(v0.rbegin(), v0.rend(),
				std::ostream_iterator <int>(std::cout, "\n"));

	return 0;
}