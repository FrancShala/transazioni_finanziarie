#include <iostream>
#include "ContoCorrente.h"
#include "Transazione.h"


int main() {
    ContoCorrente mioConto("Franc Shala");

    mioConto.aggiungiTransazione(Transazione(1000.0, "deposito", "2025-09-01", "Stipendio mensile"));
    mioConto.aggiungiTransazione(Transazione(200.0, "prelievo", "2025-09-05", "Spesa alimentare"));
    mioConto.aggiungiTransazione(Transazione(150.0, "prelievo", "2025-09-10", "Pagamento bollette"));

    std::cout << "Intestatario: " << mioConto.getIntestatario() << std::endl;
    std::cout << "Saldo attuale: " << mioConto.getSaldo() << "euro" << std::endl;

    std::cout << "Transazioni:\n" << mioConto.visualizzaTransazioni() << std::endl;

    return 0;
}
