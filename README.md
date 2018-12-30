# TInterpreter
Un interprete sencillo de comandos de caracter que se puede utilizar con microcontroladores como Arduino.  Una secuencia de comandos es un string, donde cada letra es un literal al cual se le puede asociar una función.

Se provee un ejemplo sencillo de uso haciendo un Blink. El ejemplo es suficientemente sencillo para entender su utilización. Básicamente se crear un función o procedimiento con las aciones que el microcontrolador requiere hacer, y este luego se asocia a literal

Construí esta librería con propósitos educativos, pero al mismo tiempo para poder contruir secuencias de acciones que puedan ser modificadoas en tiempo real, o que inlcuso crear sistemas evoluctivos, donde una cadena de caracteres describe la secuencia de acciones de un microcontrolador, y esta cadena se puede someter a procesos de optimización y evolución. (luego publico la librería completa)

## Uso

Declarar el objeto TInterpreter:

```
TInterpreter interpreter(3);
```
En este caso se declara con tres comandos.  Luego en setup (o cualquier otro lado antes de usarlo), se establece la relación de un literal con una funcion,
```
interpreter.add('P', &ledOn);
```
El literal "P" se asocia con la función ledOn.  Luego se declara la función,
```
void ledOn() {
  digitalWrite(13,HIGH);
}
```
