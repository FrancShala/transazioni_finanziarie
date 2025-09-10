#include <iostream>
#include "ContoCorrente.h"
#include "Transazione.h"


int main() {
    ContoCorrente conto("Franc Shala");

    conto.aggiungiTransazione(Transazione(1000, "deposito", "2025-09-01", "Stipendio mensile"));
    conto.aggiungiTransazione(Transazione(200, "prelievo", "2025-09-05", "Spesa alimentare"));
    conto.aggiungiTransazione(Transazione(150, "prelievo", "2025-09-10", "Pagamento bollette"));

    std::cout << "Intestatario: " << conto.getIntestatario() << "\n";
    std::cout << "Saldo attuale: " << conto.getSaldo() << " euro\n";
    std::cout << "Transazioni:\n" << conto.visualizzaTransazioni() << std::endl;

    conto.salvaSuFileEApri("conto_corrente.txt");

    conto.leggiDaFile("conto_corrente.txt");

    return 0;
}
