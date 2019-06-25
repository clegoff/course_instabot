make clean; make;
sudo mount /dev/sda /media/nucleo;
sudo cp .build/course_instabot.bin /media/nucleo/;sync;
sudo umount /media/nucleo
