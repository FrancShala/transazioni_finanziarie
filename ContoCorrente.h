//
// Created by franc on 03/09/2025.
//

#ifndef TRANSAZIONI_FINANZIARIE_CONTOCORRENTE_H
#define TRANSAZIONI_FINANZIARIE_CONTOCORRENTE_H

#include "Transazione.h"
#include <vector>
#include <string>

class ContoCorrente {
private:
    std::string intestatario;
    std::vector<Transazione> transazioni; // vettore di transazioni

public:
    // Costruttore
    ContoCorrente(const std::string &nome);

    void aggiungiTransazione(const Transazione &t);
    double getSaldo() const;
    std::string getIntestatario() const;
    const std::vector<Transazione>& getTransazioni() const;
    std::string visualizzaTransazioni() const;
};


#endif //TRANSAZIONI_FINANZIARIE_CONTOCORRENTE_H
