#!/bin/bash

# 备份原有的仓库配置文件
mkdir -p /etc/yum.repos.d/backup
mv /etc/yum.repos.d/*.repo /etc/yum.repos.d/backup/

# 获取 Fedora 版本号
fedora_version=$(grep -oE '[0-9]+' /etc/fedora-release | head -1)

# 创建 Fedora 主仓库配置文件
cat > /etc/yum.repos.d/fedora.repo << EOF
[fedora]
name=Fedora $fedora_version - \$basearch - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/$fedora_version/Everything/\$basearch/os/
enabled=1
metadata_expire=28d
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch

[fedora-debuginfo]
name=Fedora $fedora_version - \$basearch - Debug - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/$fedora_version/Everything/\$basearch/debug/tree/
enabled=0
metadata_expire=28d
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch

[fedora-source]
name=Fedora $fedora_version - Source - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/releases/$fedora_version/Everything/source/tree/
enabled=0
metadata_expire=28d
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch
EOF

# 创建 Fedora 更新仓库配置文件
cat > /etc/yum.repos.d/fedora-updates.repo << EOF
[updates]
name=Fedora $fedora_version - \$basearch - Updates - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/updates/$fedora_version/Everything/\$basearch/
enabled=1
metadata_expire=6h
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch

[updates-debuginfo]
name=Fedora $fedora_version - \$basearch - Updates - Debug - TUNA
failovermethod=priority
baseurl=https://mirrors.tuna.tsinghua.edu.cn/fedora/updates/$fedora_version/Everything/\$basearch/debug/tree/
enabled=0
metadata_expire=6h
gpgcheck=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-fedora-$fedora_version-\$basearch

[updates-source]
name=Fedora $fedora_version - Updates - Source - TUNA
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
