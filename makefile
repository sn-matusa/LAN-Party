build:
	g++ main.cpp Player.cpp Team.cpp lista.cpp coada.cpp meci.cpp stiva.cpp nod_bst.cpp nod_avl.cpp -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm lanParty
