

//http://openwall.info/wiki/people/solar/software/public-domain-source-code/md5
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



Thread* ThreadLoop1;

WLanSelectAntenna_TypeDef AntSel;


void setup() {
  Serial.begin(9600);

  ThreadLoop1 = new Thread("Loop1", Loop1);

  AntSel = ANT_EXTERNAL;

  WiFi.selectAntenna(AntSel);
}


void loop() {
    //Main loop does nothing
}

os_thread_return_t Loop1(void* param){
    int State=LOW;
    for(;;) {
        State = not(State);
        DoLoop1(State);
    }
}




void DoLoop1(int State) {

  Serial.println();
  Serial.println("Application>\tStart of Loop.");

  String line;
  String Res;

  line = "grape";

  Res = md5(line);

  Serial.print("md5 of grape ");
  Serial.println(Res);

}
