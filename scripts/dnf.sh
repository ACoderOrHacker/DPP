#!/bin/bash

sudo cat > /etc/yum.repos.d/fedora.repo << EOF
[fedora]
name=Fedora-TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/39/Everything/\$basearch/os/
enabled=1
metadata_expire=28d
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-39-\$basearch

[fedora-debuginfo]
name=Fedora-TUNA-Debug
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/39/Everything/\$basearch/debug/tree/
enabled=0
metadata_expire=28d
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-39-\$basearch

[fedora-source]
name=Fedora
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/39/Everything/source/tree/
enabled=0
metadata_expire=28d
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-39-\$basearch
EOF

sudo cat > /etc/yum.repos.d/fedora-updates.repo << EOF
[updates]
name=Fedora Updates - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/updates/39/Everything/\$basearch/
enabled=1
metadata_expire=6h
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-39-\$basearch

[updates-debuginfo]
name=Fedora - Updates - Debug - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/updates/39/Everything/\$basearch/debug/tree/
enabled=0
metadata_expire=6h
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-39-\$basearch

[updates-source]
name=Fedora - Updates - Source - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/updates/39/Everything/source/tree/
enabled=0
metadata_expire=6h
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-39-\$basearch
EOF

sudo chmod 644 /etc/yum.repos.d/fedora.repo
sudo chmod 644 /etc/yum.repos.d/fedora-updates.repo
