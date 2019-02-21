# GroundStationMockup

Arduino mockup for Antares ground station

Program co sekundę wysyła na port szeregowy pakiety imitujące pakiety otrzymane przez stacje naziemną.
* Wysokość zaczyna od 0 i wzrasta o 10 z każdym obiegiem pętli,
* Szerokość geograficzna zaczyna od 5422.77318 N i wzrasta o 0.00100 z każdym obiegiem pętli,
* Długość geograficzna zaczyna od 1836.39024 E i wzrasta o 0.00100 z każdym obiegiem pętli,
* Średnia temperatura zaczyna od 36.00 i oscyluje między 35.50 a 37.50,
* TempInfo - status każdej próbki przechodzi cykl `00`->`01`->`10`->`11`, czyli całe 3 bajty zmieniają się tak:
`000000000000000000000000` -> `010101010101010101010101` -> `101010101010101010101010` -> `111111111111111111111111` itd. 
* Ostatnio odebrana ramka - cały czas równa `0x0001`,
* Status - po kolei jest ustawiany jeden bit od najmniej znaczącego, tzn: 
`0000000000000000` -> `0000000000000001` -> `0000000000000010` -> `0000000000000100` itd. 
* Status komórek - jw.
