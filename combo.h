#ifndef COMBO_H
#define COMBO_H

#include "onePlayer.h"

class combo{

    public:
        vector<onePlayer> allCombo(onePlayer);
        void comboSummary(onePlayer);
        vector<onePlayer> allComboForAll();
};

#endif