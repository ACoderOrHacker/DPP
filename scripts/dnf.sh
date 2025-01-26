#!/bin/bash

sudo cat > /etc/yum.repos.d/fedora.repo << EOF
[fedora]
name=Fedora-TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/41/Everything/\$basearch/os/
enabled=1
metadata_expire=28d
gpgcheck=0
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-41-\$basearch
EOF

sudo cat > /etc/yum.repos.d/fedora-updates.repo << EOF
[updates]
name=Fedora Updates - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/updates/41/Everything/\$basearch/
enabled=1
metadata_expire=6h
gpgcheck=0
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-41-\$basearch
EOF

sudo chmod 644 /etc/yum.repos.d/fedora.repo
sudo chmod 644 /etc/yum.repos.d/fedora-updates.repo
