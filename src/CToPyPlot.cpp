#include "CToPyPlot.hpp"

namespace CTPP {

/**
 * @brief python wrapper for drawing data vector
 * @details matplotlib is used to plot data.
 * The data is record in a raw file : /local/.CTPP/tempVector.data.
 * the scripts python load the data of the file and use it.
 *
 * @param type Data type
 * @param ptr Data pointer
 * @param nbData Number of data
 */
void CToPyPlot::drawVector(dataType type, void* ptr, int nbData)
{
  std::string path = vectorPath;
  std::string cmd;
  int error = 0;

  // Create workDir
  if (!boost::filesystem::exists(workDir)){
    std::cout << "[CToPyPlot] You have to launch initLibrary.py" << std::endl;
    exit(-1);
  }

  // Delete tmp file if exist
  if ( std::ifstream(path.c_str()) )
    cmd = "rm -rf " + path;
    error = system(cmd.c_str());

  // Write datas in file
  FILE *fp;
  fp = fopen(path.c_str(), "w");
  if (fp == NULL)
    exit(-1);
  if (type == Int16){
    fwrite((short*)ptr, sizeof(short), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 1 " + workDir + " 0 title";
  }
  else if (type == Int32){
    fwrite((int*)ptr, sizeof(int), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 2 " + workDir + " 0 title";
  }
  else if (type == Float){
    fwrite((float*)ptr, sizeof(float), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 3 " + workDir + " 0 title";
  }
  else if (type == Double){
    fwrite((double*)ptr, sizeof(double), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 4 " + workDir + " 0 title";
  }
  else if (type == CplxInt16){
    fwrite((short*)ptr, sizeof(std::complex<short>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 5 " + workDir + " 0 title";
  }
  else if (type == CplxInt32){
    fwrite((int*)ptr, sizeof(std::complex<int>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 6 " + workDir + " 0 title";
  }
  else if (type == CplxFloat){
    fwrite((float*)ptr, sizeof(std::complex<float>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 7 " + workDir + " 0 title";
  }
  else if (type == CplxDouble){
    fwrite((double*)ptr, sizeof(std::complex<double>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 8 " + workDir + " 0 title";
  }
  else{
    std::cout << "[CToPyPlot] Error data Type" << std::endl;
    exit(-1);
  }

  // Launch python script to draw data
  error = system(cmd.c_str());

  // Delete tmp file
  cmd = "rm -rf " + vectorPath;
  error = system(cmd.c_str());
}

/**
 * @brief python wrapper for recording data vector
 * @details matplotlib is used to plot data.
 * The data is record in a raw file : /local/.CTPP/tempVector.data.
 * the scripts python load the data of the file and use it.
 *
 * @param type Data type
 * @param ptr Data pointer
 * @param nbData Number of data
 */
void CToPyPlot::recordFig(dataType type, void* ptr, int nbData, const char* title)
{
  std::string path = vectorPath;
  std::string cmd;

  int error = 0;

  // Create workDir
  if (!boost::filesystem::exists(workDir)){
    std::cout << "[CToPyPlot] You have to launch initLibrary.py" << std::endl;
    exit(-1);
  }

  // Delete tmp file if exist
  if ( std::ifstream(path.c_str()) )
    cmd = "rm -rf " + path;
    error = system(cmd.c_str());

  // Write datas in file
  FILE *fp;
  fp = fopen(path.c_str(), "w");
  if (fp == NULL)
    exit(-1);
  if (type == Int16){
    fwrite((short*)ptr, sizeof(short), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 1 " + workDir + " 1 " + title;
  }
  else if (type == Int32){
    fwrite((int*)ptr, sizeof(int), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 2 " + workDir + " 1 " + title;
  }
  else if (type == Float){
    fwrite((float*)ptr, sizeof(float), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 3 " + workDir + " 1 " + title;
  }
  else if (type == Double){
    fwrite((double*)ptr, sizeof(double), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 4 " + workDir + " 1 " + title;
  }
  else if (type == CplxInt16){
    fwrite((short*)ptr, sizeof(std::complex<short>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 5 " + workDir + " 1 " + title;
  }
  else if (type == CplxInt32){
    fwrite((int*)ptr, sizeof(std::complex<int>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 6 " + workDir + " 1 " + title;
  }
  else if (type == CplxFloat){
    fwrite((float*)ptr, sizeof(std::complex<float>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 7 " + workDir + " 1 " + title;
  }
  else if (type == CplxDouble){
    fwrite((double*)ptr, sizeof(std::complex<double>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 8 " + workDir + " 1 " + title;
  }
  else{
    std::cout << "[CToPyPlot] Error data Type" << std::endl;
    exit(-1);
  }

  // Launch python script to draw data
  error = system(cmd.c_str());

  // Delete tmp file
  cmd = "rm -rf " + vectorPath;
  error = system(cmd.c_str());
}

/**
 * @brief record raw data
 * The data is record in the folder: /tmp/.CTPP.
 *
 * @param type Data type
 * @param ptr Data pointer
 * @param nbData Number of data
 */
void CToPyPlot::recordRawData(dataType type, void* ptr, int nbData, const char* title)
{
  std::string path = workDir + "/" + title;
  std::string cmd;

  int error = 0;

  // Create workDir
  if (!boost::filesystem::exists(workDir)){
    std::cout << "[CToPyPlot] You have to launch initLibrary.py" << std::endl;
    exit(-1);
  }

  // Delete tmp file if exist
  if ( std::ifstream(path.c_str()) )
    cmd = "rm -rf " + path;
    error = system(cmd.c_str());

  // Write datas in file
  FILE *fp;
  fp = fopen(path.c_str(), "w");
  if (fp == NULL)
    exit(-1);
  if (type == Int16){
    fwrite((short*)ptr, sizeof(short), nbData, fp);
    fclose(fp);
  }
  else if (type == Int32){
    fwrite((int*)ptr, sizeof(int), nbData, fp);
    fclose(fp);
  }
  else if (type == Float){
    fwrite((float*)ptr, sizeof(float), nbData, fp);
    fclose(fp);
  }
  else if (type == Double){
    fwrite((double*)ptr, sizeof(double), nbData, fp);
    fclose(fp);
  }
  else if (type == CplxInt16){
    fwrite((short*)ptr, sizeof(std::complex<short>), nbData, fp);
    fclose(fp);
  }
  else if (type == CplxInt32){
    fwrite((int*)ptr, sizeof(std::complex<int>), nbData, fp);
    fclose(fp);
  }
  else if (type == CplxFloat){
    fwrite((float*)ptr, sizeof(std::complex<float>), nbData, fp);
    fclose(fp);
  }
  else if (type == CplxDouble){
    fwrite((double*)ptr, sizeof(std::complex<double>), nbData, fp);
    fclose(fp);
  }
  else{
    std::cout << "[CToPyPlot] Error data Type" << std::endl;
    exit(-1);
  }
}

/**
 * @brief python wrapper for drawing complex constellation
 * @details matplotlib is used to plot data.
 * The data is record in a raw file : /local/.CTPP/tempVector.data.
 * the scripts python load the data of the file and use it.
 *
 * @param type Data type
 * @param ptr Data pointer
 * @param nbData Number of data
 */
void CToPyPlot::drawConstellation(dataType type, void* ptr, int nbData)
{
  std::string path = vectorPath;
  std::string cmd;
  int error = 0;

  // Create workDir
  if (!boost::filesystem::exists(workDir)){
    std::cout << "[CToPyPlot] You have to launch initLibrary.py" << std::endl;
    exit(-1);
  }

  // Delete tmp file if exist
  if ( std::ifstream(path.c_str()) )
    cmd = "rm -rf " + path;
    error = system(cmd.c_str());

  // Write datas in file
  FILE *fp;
  fp = fopen(path.c_str(), "w");
  if (fp == NULL)
    exit(-1);
  if (type == CplxInt16){
    fwrite((short*)ptr, sizeof(std::complex<short>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 5 " + workDir + " 2 title";
  }
  else if (type == CplxInt32){
    fwrite((int*)ptr, sizeof(std::complex<int>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 6 " + workDir + " 2 title";
  }
  else if (type == CplxFloat){
    fwrite((float*)ptr, sizeof(std::complex<float>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 7 " + workDir + " 2 title";
  }
  else if (type == CplxDouble){
    fwrite((double*)ptr, sizeof(std::complex<double>), nbData, fp);
    fclose(fp);
    cmd = workDir + "/DrawVector.py 8 " + workDir + " 2 title";
  }
  else{
    std::cout << "[CToPyPlot] Error data Type" << std::endl;
    exit(-1);
  }

  // Launch python script to draw data
  error = system(cmd.c_str());

  // Delete tmp file
  cmd = "rm -rf " + vectorPath;
  error = system(cmd.c_str());
}

};