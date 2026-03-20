# TEMA-1-POO


 Proiect: Calcularea profitului/pierderii pentru clienți la pariuri sportive

  Descrierea problemei:
    Programul simulează pariuri pe meciuri și calculează bugetul final al fiecărui client,
    în funcție de rezultatele meciurilor și pariurile plasate.

  Datele de intrare:
    - Primul rând: un număr n, reprezentând numărul de meciuri.
    - Următoarele n rânduri: date despre fiecare meci, câte un rând pe meci, format:
        <echipa1> <echipa2> <cota_echipa1> <cota_egal> <cota_echipa2> <rezultat>
      unde:
        - echipa1, echipa2: numele celor două echipe
        - cota_echipa1, cota_egal, cota_echipa2: cote pentru fiecare rezultat
        - rezultat: rezultatul final al meciului (echipa1, echipa2 sau egal)
    - Următorul rând: un număr m, reprezentând numărul de clienți.
    - Pentru fiecare client:
        - Un rând cu: <nume> <prenume> <buget_initial> <numar_pariuri>
        - Următoarele <numar_pariuri> rânduri: detalii despre fiecare pariu:
            <suma> <alegere> <index_meci>
          unde:
            - suma: suma pariului
            - alegere: "echipa1", "echipa2" sau "egal"
            - index_meci: indexul meciului pe care s-a pariat (0-based)

   Operațiile posibile:
    - Setarea rezultatelor meciurilor
    - Calcularea profitului sau pierderii pentru fiecare pariu
    - Calcularea bugetului final al fiecărui client
    - Adăugarea unui nou pariu la un client
    - Compararea bugetului final cu bugetul inițial pentru a verifica dacă a realizat profit
    - Afișarea informațiilor despre client: nume, prenume, buget final și simbol de profit/pierdere
