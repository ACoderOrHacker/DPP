# Plugins

## Introduction

This folder is all the standard plugins for the project (venv, etc)

## Installation
```
xmake f --enable-plugins=y
xmake
```

## Usage

### venv
- create: dpp -p --commands venv -o [your venv folder]
- activate: dpp -p --commands venv -a activate:[venv folder]
- deactivate: dpp -p --commands venv -a deactivate:[venv folder]