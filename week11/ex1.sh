dd if=/dev/zero of=lofs.img bs=1024 count=51200
/sbin/mkfs lofs.img 
mkdir lofsdisk
sudo mount -o loop=/dev/loop18 lofs.img lofsdisk
chmod 777 lofsdisk/
