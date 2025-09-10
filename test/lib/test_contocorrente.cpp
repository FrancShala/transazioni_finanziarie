//
// Created by franc on 10/09/2025.
//
#include "gtest/gtest.h"
#include "../../ContoCorrente.h"
#include "../../Transazione.h"

TEST(ContoCorrenteTest, CostruttoreEGetter) {
ContoCorrente conto("Franc");
EXPECT_EQ(conto.getIntestatario(), "Franc");
EXPECT_EQ(conto.getSaldo(), 0.0);
EXPECT_TRUE(conto.getTransazioni().empty());
}

TEST(ContoCorrenteTest, AggiungiTransazioneESaldo) {
ContoCorrente conto("Franc");
conto.aggiungiTransazione(Transazione(100.0, "deposito", "2025-09-10", "Stipendio"));
conto.aggiungiTransazione(Transazione(50.0, "prelievo", "2025-09-11", "Spesa"));

EXPECT_EQ(conto.getSaldo(), 50.0);
EXPECT_EQ(conto.getTransazioni().size(), 2);
}

TEST(ContoCorrenteTest, VisualizzaTransazioni) {
ContoCorrente conto("Franc");
conto.aggiungiTransazione(Transazione(100.0, "deposito", "2025-09-10", "Stipendio"));
conto.aggiungiTransazione(Transazione(50.0, "prelievo", "2025-09-11", "Spesa"));

std::string expected =
        "Data: 2025-09-10, Tipo: deposito, Importo: 100.000000, Descrizione: Stipendio\n"
        "Data: 2025-09-11, Tipo: prelievo, Importo: 50.000000, Descrizione: Spesa\n";

EXPECT_EQ(conto.visualizzaTransazioni(), expected);
}