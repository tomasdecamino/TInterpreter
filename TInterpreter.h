/****************************************************
Written by Tomas de Camino Beck.
tomas@funcostarica.org

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

***************************************************************/

struct action {
  char literal;
  void (*actionDef)();//pointer to action function
};

class TInterpreter {
  public:
    uint8_t current = 0;
    uint8_t exeComand = 0;
    //array where actions are stored
    action* actionSet;
    uint8_t nActions; //number of actions

    TInterpreter(uint8_t n) {
      nActions = n;
      actionSet = new action[n];

    }

    void add(uint8_t i, char l, void f()) {
      actionSet[i].literal = l;
      actionSet[i].actionDef = f;

    }

    void add(char l, void f()) {
      actionSet[current].literal = l;
      actionSet[current].actionDef = f;
      current++;

    }

    void execute(String cmd) {
      for (uint8_t i = 0; i < cmd.length(); i++) {
        exeComand = i;
        int8_t sel = findAction(cmd[i]);
        if (sel > -1) {
          actionSet[sel].actionDef();
        }
      }
    }

    uint8_t findAction(char l) {
      int8_t sel = -1;
      for (uint8_t i = 0; i < nActions; i++) {
        if (actionSet[i].literal == l) sel = i;
      }
      return sel;
    }

    char getExecuted(){
      return actionSet[exeComand].literal;
    }
};
