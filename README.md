
About
=====
This is the port for the Particle Photon of the port by Solar Designer
http://openwall.info/wiki/people/solar/software/public-domain-source-code/md5

According to the website "This code is used in Openwall's popa3d and blists, as well as in PHP 5.3.0+, ClamAV, Dovecot, Eggdrop, FreeType, masqmail, Staden Package io_lib, and more."

This was imported from the above site to allow HTTP Digest Authentication in conjunction with the HttpClient application.



Example Usage
=============

    #include "md5.h"
    #include "application.h"
    
    String md5(String line) {
      unsigned char result[16];
    
      MD5_CTX hash;
      MD5_Init(&hash);
      MD5_Update(&hash, line, line.length());
      MD5_Final(result, &hash);
    
      char buf[33];
      for (int i=0; i<16; i++)
        sprintf(buf+i*2, "%02x", result[i]);
      buf[32]=0;
    
      return String(buf);
    }
    ...
    line = "grape";
    Res = md5(line);
    ...

This returns the md5 hex string for "grape"

md5 of grape b781cbb29054db12f88f08c6e161c199

See example directory
test_md5.ino


This can be checked with python

    import hashlib
    name="grape"
    hash1 = hashlib.md5(name).hexdigest()
    print hash1



