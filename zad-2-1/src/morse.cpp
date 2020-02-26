#include <Arduino.h>
#include <morse.h>
#include <string.h>
#include <ctype.h>

void sendCode(char *code, uint8_t pin);
char *encode(char c);

void morseSend(const char *message, uint8_t pin)
{
    size_t messageLength = strlen((char *)message);
    pinMode(pin, OUTPUT);

    for (uint8_t i = 0; i < messageLength; i++)
    {
        if (message[i] == ' ')
        {
            delay(M_SPACJA_T);
        }
        else
        {
            sendCode(encode(tolower((char)message[i])), pin);
        }
    }
}

void sendCode(char *code, uint8_t pin)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        if (code[i] == '.')
        {
            digitalWrite(pin, HIGH);
            delay(M_KROPKA_T);
            digitalWrite(pin, LOW);
            delay(M_PAUZA_T);
        }
        else if (code[i] == '-')
        {
            digitalWrite(pin, HIGH);
            delay(M_KRESKA_T);
            digitalWrite(pin, LOW);
            delay(M_PAUZA_T);
        }
        else
        {
            return;
        }
    }
}

char *encode(char c)
{
    switch (c)
    {
    case 'a':
        return (char *)".-";
    case 'b':
        return (char *)"-...";
    case 'c':
        return (char *)"-.-.";
    case 'd':
        return (char *)"-..";
    case 'e':
        return (char *)".";
    case 'f':
        return (char *)"..-.";
    case 'g':
        return (char *)"--.";
    case 'h':
        return (char *)"....";
    case 'i':
        return (char *)"..";
    case 'j':
        return (char *)".---";
    case 'k':
        return (char *)"-.-";
    case 'l':
        return (char *)".-..";
    case 'm':
        return (char *)"--";
    case 'n':
        return (char *)"-.";
    case 'o':
        return (char *)"---";
    case 'p':
        return (char *)".--.";
    case 'q':
        return (char *)"--.-";
    case 'r':
        return (char *)".-.";
    case 's':
        return (char *)"...";
    case 't':
        return (char *)"-";
    case 'u':
        return (char *)"..-";
    case 'v':
        return (char *)"...-";
    case 'w':
        return (char *)".--";
    case 'x':
        return (char *)"-..-";
    case 'y':
        return (char *)"-.--";
    // for space
    case 'z':
        return (char *)"--..";
    default:
        return (char *)" ";
    }
}