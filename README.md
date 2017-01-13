# The ROBOT

Modelați comportamentul unui robot într-o lume simplă de blocuri, respectând anumite reguli de bază. Vor trebui executate o serie de comenzi care îi specifică robotului cum să mute blocurile aflate pe o masă. Inițial, există n blocuri pe masă (numerotate de la 0 la n - 1), în care blocul i este vecin cu blocul i + 1, pentru orice 0 ≤  i  ≤ n – 1.

Comenzile valide pentru brațele robotului care4 manipulează blocurile sunt:

move a onto b: unde a și b sunt numere de blocuri, pune blocul a peste blocul b după ce returnează toate blocurile care sunt stivuite deasupra blocurilor a și b la pozițiile lor inițiale.

move a over b: unde a și b sunt numere de blocuri, pune blocul a în vârful stivei care conține blocul b, după ce returnează toate blocurile care sunt stocate deasupra lui a in pozitiile lor initiale.

pile a onto b: unde a și b sunt numere de blocuri, mută stiva de blocuri care începe cu blocul a, deasupra blocului b. Toate blocurile stivuite deasupra blocului b sunt mutate la pozitiile lor initiale inainte de a le mută pe cele de deasupra blocului a. Blocurile stocate deasupra blocului a își mențin ordinea atunci când sunt mutate.

pile a over b: unde a și b sunt numere de blocuri, mută stiva de blocuri care începe cu blocul a și toate blocurile care sunt stivuite deasupra blocului a peste stiva de blocuri care îl conține pe blocul b.

quit: termină manipularea blocurilor.
 
Observatie: Orice comandă cu a = b sau cu a și b sunt în aceeași stivă de blocuri este o comandă ilegală. Toate comenzile ilegale trebuie ignorate și nu pot modifica configurația blocurilor.

Datele de intrare încep cu un întreg n pe o linie, acesta reprezentând numărul de blocuri din lumea bloculețelor. Considerăm că n este în intervalul: 0 < n < 25. Numărul blocurilor este urmat de o secvență de comenzi, câte una pe linie. Programul trebuie să proceseze toate comenzile până când este citită comanda quit. Presupunem că toate comenzile sunt de forma specificată mai sus.

Datele de ieșire trebuie să descrie starea finală din lumea bloculețelor. Fiecare poziție inițială, numerotată cu i (0 ≤  i  < n, unde n este numărul de blocuri) trebuie să apară urmată imediat de “:”. 

Dacă există cel puțin un bloc acolo, trebuie să urmeze pe această linie un spațiu, apoi lista blocurilor care apar stocate în acea pozție, numerele fiind separate de câte un spațiu. Trebuie să existe o linie de ieșire pentru fiecare poziție de bloc.
 
Exemplu: 

Intrare: 11                             	

       move 10 over 1
       move 4 over 7
    	 move 7 onto 1
    	 move 6 over 4
    	 move 1 over 4
    	 pile 4 over 8
    	 move 6 onto 8
    	 pile 3 onto 6
    	 quit 
 
Iesire: 

       0: 0
    	 1: 1
    	 2: 2
    	 3:
    	 4:
    	 5: 5
    	 6:
    	 7: 7
    	 8: 8 4 6 3
    	 9: 9
    	10: 10      

