//
// Created by franc on 10/09/2025.
//
#include "gtest/gtest.h"
#include "../../Transazione.h"  // percorso relativo al file header

TEST(TransazioneTest, CostruttoreEGetter) {
Transazione t(100.0, "deposito", "2025-09-10", "Stipendio");

EXPECT_DOUBLE_EQ(t.getImporto(), 100.0);
EXPECT_EQ(t.getTipo(), "deposito");
EXPECT_EQ(t.getData(), "2025-09-10");
EXPECT_EQ(t.getDescrizione(), "Stipendio");
}

TEST(TransazioneTest, VisualizzaDettagli) {
Transazione t(50.0, "prelievo", "2025-09-11", "Spesa");
std::string expected = "Data: 2025-09-11, Tipo: prelievo, Importo: 50.000000, Descrizione: Spesa";
EXPECT_EQ(t.visualizzaDettagli(), expected);
}