//
// Created by franc on 03/09/2025.
//

#include "ContoCorrente.h"

ContoCorrente::ContoCorrente(const std::string &nome) : intestatario(nome){}

void ContoCorrente::aggiungiTransazione(const Transazione &t) {
    transazioni.push_back(t);
}

double ContoCorrente::getSaldo() const {
    double saldo = 0.0;
    for (const auto &t : transazioni) {
        if (t.getTipo() == "deposito") {
            saldo += t.getImporto();
        } else if (t.getTipo() == "prelievo") {
            saldo -= t.getImporto();
        }
    }
    return saldo;
}

std::string ContoCorrente::getIntestatario() const {
    return intestatario;
}

const std::vector<Transazione>& ContoCorrente::getTransazioni() const {
    return transazioni;
}

std::string ContoCorrente::visualizzaTransazioni() const {
    std::string risultato;
    for (const auto &t : transazioni) {
        risultato += t.visualizzaDettagli() + "\n";
    }
    return risultato;
}
