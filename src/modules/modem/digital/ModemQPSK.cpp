#include "ModemQPSK.h"

ModemQPSK::ModemQPSK() {
    demodQPSK = modem_create(LIQUID_MODEM_QPSK);
}

Modem *ModemQPSK::factory() {
    return new ModemQPSK;
}

ModemQPSK::~ModemQPSK() {
    modem_destroy(demodQPSK);
}

void ModemQPSK::demodulate(ModemKit *kit, ModemIQData *input, AudioThreadInput *audioOut) {
    
    for (int i = 0, bufSize = input->data.size(); i < bufSize; i++) {
        modem_demodulate(demodQPSK, input->data[i], &demodOutputDataDigital[i]);
    }
    updateDemodulatorLock(demodQPSK, 0.8f);
}