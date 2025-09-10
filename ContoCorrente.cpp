//
// Created by franc on 03/09/2025.
//

#include "ContoCorrente.h"
#include "fstream"
#include "cstdlib"
#include "iostream"

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

void ContoCorrente::salvaSuFile(const std::string &nomeFile) const {
    std::ofstream file(nomeFile);
    if (file.is_open()) {
        file << "Intestatario: " << intestatario << "\n";
        file << "Saldo attuale: " << getSaldo() << " euro\n";
        file << "Transazioni:\n";
        for (const auto &t : transazioni) {
            file << t.visualizzaDettagli() << "\n";
        }
        file.close();
    } else {
        std::cout << "Errore nell'apertura del file!" << std::endl;
    }
}

void ContoCorrente::salvaSuFileEApri(const std::string &nomeFile) const {
    salvaSuFile(nomeFile);
    system(("notepad " + nomeFile).c_str());
}

void ContoCorrente::leggiDaFile(const std::string& nomeFile) const {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile aprire il file " << nomeFile << std::endl;
        return;
    }

    std::string riga;
    std::cout << "\n--- Dati caricati da file ---\n";
    while (std::getline(file, riga)) {
        std::cout << riga << std::endl;
    }
    file.close();
}