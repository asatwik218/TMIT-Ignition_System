# TMIT-Ignition_System

Ignition system code written for THRUSTMIT. On the transmitting side an RF module (NRF24L01) sends an ignition command on pressing the safety, arm and launch button in that paritcular order. On the receiving side another rf module receives the command and send pwm signal to a relay/mosfet to send current to the ignitors.

the receiving side also has functionality to store loadcell data when used for motor tests.
