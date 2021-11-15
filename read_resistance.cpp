// This program calculates the resistance of a lower resistor in a voltage divider circuit
// connected betweem Vout and ground. 
#include "Analogin.h"
#include<iostream>
using std::cout;
using std::endl;
using std::string;

int main(){
	Analogin tmp36(0);
	int ADC_raw = tmp36.readADCsample(); 
	float ADC_voltage, resistance;
	static float R1 = 10000;

	cout << "Reading ADC Channel " << tmp36.getNumber() << endl;	
	cout << "Raw ADC value: " << ADC_raw << endl;

	ADC_voltage = ADC_raw*(float)1.8/(float)4095;
	cout << "Voltage value: " << ADC_voltage << endl;

	resistance = R1/((1.8/ADC_voltage)-1);
	if (resistance >= 1000)
		cout << "Resistance: " << resistance/1000 << " kOhms" << endl;
	else if (resistance == 1)
		cout << "Resistance: " << resistance << " Ohm" << endl;
	else
		cout << "Resistance: " << resistance << " Ohms" << endl;
}
