# Wiring Guide

## NodeMCU Pin Mapping (example)
- D2 (GPIO4) -> DHT data pin (with 10K pull-up)
- D1 (GPIO5) -> Relay IN
- 3.3V -> DHT VCC (if using DHT22)
- GND -> Common ground
- PIR VCC -> 5V (if required by PIR), PIR OUT -> D5 (GPIO14)

## Relay Notes
- Use an opto-isolated relay module if possible.
- Relay VCC should be powered from a stable 5V source.
- DO NOT switch mains directly with jumper wires; use proper connectors and enclosures.

## Example
See `images/wiring_diagram.png` for an example breadboard wiring diagram.
