#define MyAppName "D++"
#define MyAppVersion "0.1"
#define MyAppURL "ACoderOrHacker.github.io"

[Setup]
AppId={{9BCA5CBD-B20B-46E0-9718-229F2F02225F}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\DPP
DefaultGroupName={#MyAppName}
LicenseFile=..\..\LICENSE
OutputDir=..\..\pack\installer
OutputBaseFilename=DPP-setup
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
Source: "..\..\pack\DPP\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

