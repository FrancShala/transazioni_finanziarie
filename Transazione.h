//
// Created by franc on 03/09/2025.
//

#ifndef TRANSAZIONI_FINANZIARIE_TRANSAZIONE_H
#define TRANSAZIONI_FINANZIARIE_TRANSAZIONE_H

#include <string>

class Transazione {
private:
    double importo;
    std::string tipo; // "deposito" o "prelievo"
    std::string data;
    std::string descrizione;

public:
    // Costruttore
    Transazione(double importo, const std::string &tipo, const std::string &data, const std::string &descrizione);

    // Metodi getter
    double getImporto() const;
    std::string getTipo() const;
    std::string getData() const;
    std::string getDescrizione() const;

    // Metodo per visualizzare i dettagli della transazione
    std::string visualizzaDettagli() const;
};


#endif //TRANSAZIONI_FINANZIARIE_TRANSAZIONE_H
