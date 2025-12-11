## 📂 **Navigation**

```bash
pwd                   # Show current directory
ls                    # List files
ls -l                 # Long listing with permissions
ls -a                 # Include hidden files
cd /path/to/dir       # Change directory
cd ~                  # Go to home
cd ..                 # Go up one directory
cd -                  # Switch to previous directory
```

---

## 📄 **File & Directory Operations**

```bash
touch file.txt                # Create empty file
mkdir newfolder               # Create directory
mkdir -p path/to/dir          # Create nested dirs
cp file1 file2                # Copy file
cp -r dir1 dir2               # Copy directory recursively
mv old new                    # Move/rename file or directory
rm file.txt                   # Remove file
rm -r folder                  # Remove directory recursively
rm -rf folder                 # Force remove directory
```

---

## 🔐 **Permissions**

```bash
chmod 755 file                # rwxr-xr-x
chmod 644 file                # rw-r--r--
chmod u+x script.sh           # Add execute for user
chmod -R 755 folder           # Recursive permissions
```

**Meaning of digits:**

* 7 = read + write + execute
* 6 = read + write
* 5 = read + execute
* 4 = read

---

## 👤 **Ownership**

```bash
sudo chown user file          # Change owner
sudo chown user:group file    # Change owner & group
sudo chown -R user:group dir  # Recursive ownership
sudo chgrp group file         # Change group only
```

---

## 📝 **Viewing & Editing Files**

```bash
cat file.txt                  # Print file content
tac file.txt                  # Print backwards
less file.txt                 # Scrollable viewer
head file.txt                 # First 10 lines
tail file.txt                 # Last 10 lines
tail -f log.txt               # Follow log output
nano file.txt                 # Edit with nano
vim file.txt                  # Edit with vim
```

---

## 🔎 **Search**

```bash
grep "text" file              # Search in file
grep -r "text" folder         # Recursive search
grep -n "text" file           # Show line numbers
find . -name "*.txt"          # Find files by name
find / -type f -size +10M     # Find >10MB files
```

---

## 📦 **Packages (Debian/Ubuntu)**

```bash
sudo apt update               # Refresh package list
sudo apt upgrade              # Upgrade packages
sudo apt install pkg          # Install package
sudo apt remove pkg           # Remove package
sudo apt autoremove           # Cleanup unused deps
```

---

## 🔥 **Processes**

```bash
ps aux                        # List processes
top                           # Live process view
htop                          # Better view (if installed)
kill PID                      # Kill process
kill -9 PID                   # Force kill
pkill name                    # Kill by name
```

---

## 🌐 **Networking**

```bash
ping google.com               # Test connectivity
ifconfig                      # Show network interfaces
ip a                          # Newer command for interfaces
curl https://example.com      # Fetch URL
wget https://example.com/file # Download file
netstat -tulpn                # Ports & processes
ss -tulpn                     # Modern replacement for netstat
```

---

## 📦 **Tar, Zip & Compression**

```bash
tar -cvf archive.tar folder        # Create tar
tar -xvf archive.tar               # Extract tar
tar -czvf archive.tar.gz folder    # Create tar.gz
tar -xzvf archive.tar.gz           # Extract tar.gz

zip file.zip file.txt              # Create zip
unzip file.zip                     # Extract zip
```

---

## 🧰 **System Information**

```bash
uname -a                     # Kernel info
lsb_release -a               # Distro info (Ubuntu/Debian)
df -h                        # Disk usage
du -sh folder                # Folder size
free -h                      # RAM usage
uptime                       # Uptime and load
whoami                       # Current user
id                           # User and group IDs
```

---

## 🔧 **System Control**

```bash
sudo reboot                  # Reboot
sudo shutdown -h now         # Shutdown
sudo systemctl status svc    # Service status
sudo systemctl restart svc   # Restart service
sudo systemctl enable svc    # Enable at boot
```

---

## 🛠️ **Useful Misc Tools**

```bash
history                      # Command history
!!                           # Repeat last command
!123                         # Run history command #123
df -h                        # Disk space
watch -n 1 command           # Repeat command every second
```

---

## 🧹 **File Content Manipulation**

```bash
echo "text" > file           # Overwrite file
echo "text" >> file          # Append to file
cat file1 file2 > merged     # Merge files
sort file.txt                # Sort lines
uniq file.txt                # Remove duplicates
wc -l file.txt               # Count lines
```

---

## 🔒 **Sudo & User Management**

```bash
sudo su                      # Become root
sudo -i                      # Root login shell
adduser newuser              # Add new user
usermod -aG group user       # Add user to group
passwd user                  # Change password
```

---

## 🧪 **Environment & Variables**

```bash
export VAR=value             # Set variable
echo $VAR                    # Read variable
env                          # List environment variables
```
