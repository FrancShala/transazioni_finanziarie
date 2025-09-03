//
// Created by franc on 03/09/2025.
//

#include "Transazione.h"

// inizializza i membri della classe
Transazione::Transazione(double importo, const std::string &tipo, const std::string &data, const std::string &descrizione) : importo(importo), tipo(tipo), data(data), descrizione(descrizione) {}

double Transazione::getImporto() const {return importo;}
std::string Transazione::getTipo() const {return tipo;}
std::string Transazione::getData() const {return data;}
std::string Transazione::getDescrizione() const {return descrizione;}

std::string Transazione::visualizzaDettagli() const {
    return "Data: " + data + ", Tipo: " + tipo + ", Importo: " + std::to_string(importo) + ", Descrizione: " + descrizione;

}


