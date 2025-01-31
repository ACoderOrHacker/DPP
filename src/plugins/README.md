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
- create: dpp -p builtin --commands venv -o [your venv folder]
- activate: dpp -p builtin --commands venv -a activate:[venv folder]
- deactivate: dpp -p builtin --commands venv -a deactivate:[venv folder]