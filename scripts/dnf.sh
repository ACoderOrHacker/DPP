#!/bin/bash

cat > /etc/yum.repos.d/fedora.repo << EOF
[fedora]
name=Fedora-TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/$fedora_version/Everything/\$basearch/os/
enabled=1
metadata_expire=28d
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch

[fedora-debuginfo]
name=Fedora-TUNA-Debug
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/$fedora_version/Everything/\$basearch/debug/tree/
enabled=0
metadata_expire=28d
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch

[fedora-source]
name=Fedora
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/$fedora_version/Everything/source/tree/
enabled=0
metadata_expire=28d
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch
EOF

cat > /etc/yum.repos.d/fedora-updates.repo << EOF
[updates]
name=Fedora Updates - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/updates/$fedora_version/Everything/\$basearch/
enabled=1
metadata_expire=6h
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch

[updates-debuginfo]
name=Fedora - Updates - Debug - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/updates/$fedora_version/Everything/\$basearch/debug/tree/
enabled=0
metadata_expire=6h
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch

[updates-source]
name=Fedora - Updates - Source - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/updates/$fedora_version/Everything/source/tree/
enabled=0
metadata_expire=6h
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch
EOF

# 设置文件权限
chmod 644 /etc/yum.repos.d/fedora.repo
chmod 644 /etc/yum.repos.d/fedora-updates.repo

# 清理并重建dnf缓存
dnf clean all
dnf makecache
