# TF2 Classified Rewrite

## What changed
- Removed hard dependency on GiveNamedItem offset
- Added TF2C detection
- Added automatic gamedata generator
- Introduced new TF2C-native extension scaffold

## Why
TF2Items breaks on modern engines and TF2C due to binary differences.

Modern systems use econ-based access instead of schema parsing.

## Recommended stack
- TFEconData
- TF2Attributes
- CustomWeaponsX

## Status
Initial TF2C compatibility + foundation for full rewrite
