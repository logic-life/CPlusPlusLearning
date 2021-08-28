# 服务器+网站

## 服务器连接

```
ssh root@1.117.166.63
```

腾讯云上申请的免费服务器!

**通过ssh连接云服务器显示Permission denied, please try again？**

* ubuntu 需要将/etc/ssh/sshd_config文件中的将	PermitRootLogin 改为yes,去掉	PasswordAuthentication yes前的#
* 随后重启ssh服务service ssh restart

## 如何上传文件到服务器

## 宝塔服务器管理软件

外网面板地址: http://1.117.166.63:8888/logic-life
内网面板地址: http://10.0.4.12:8888/logic-life
username: thbwcssr
password: 98b2b2e7
