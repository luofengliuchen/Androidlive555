/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class luofeng_com_live555_Live555 */
#include <BasicUsageEnvironment.hh>
#include "mediaServer/DynamicRTSPServer.hh"
#include "mediaServer/version.hh"

#ifndef _Included_luofeng_com_live555_Live555
#define _Included_luofeng_com_live555_Live555
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     luofeng_com_live555_Live555
 * Method:    startLive555Serve
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_luofeng_com_live555_Live555_startLive555Serve
  (JNIEnv *env0, jobject obj){
   TaskScheduler* scheduler = BasicTaskScheduler::createNew();
   UsageEnvironment* env = BasicUsageEnvironment::createNew(*scheduler);

   UserAuthenticationDatabase* authDB = NULL;
 #ifdef ACCESS_CONTROL
   // To implement client access control to the RTSP server, do the following:
   authDB = new UserAuthenticationDatabase;
   authDB->addUserRecord("username1", "password1"); // replace these with real strings
   // Repeat the above with each <username>, <password> that you wish to allow
   // access to the server.
 #endif

   // Create the RTSP server.  Try first with the default port number (554),
   // and then with the alternative port number (8554):
   RTSPServer* rtspServer;
   portNumBits rtspServerPortNum = 554;
   rtspServer = DynamicRTSPServer::createNew(*env, rtspServerPortNum, authDB);
   if (rtspServer == NULL) {
     rtspServerPortNum = 8554;
     rtspServer = DynamicRTSPServer::createNew(*env, rtspServerPortNum, authDB);
   }
   if (rtspServer == NULL) {
     *env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
     exit(1);
   }

   env->taskScheduler().doEventLoop(); // does not return

};


#ifdef __cplusplus
}
#endif
#endif