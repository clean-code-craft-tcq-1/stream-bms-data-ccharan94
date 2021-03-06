# ----------------------------------------------------------------
# Battery Monitoring System Data Streamer:
# ----------------------------------------------------------------  
# Description: This program sends the stream data from the BMS
#              for parameters Temperature and SOC in json format
# -----------------------------------------------------------------

import random

#allowed output formats of the sensor data
allowed_formats = ['json']

#limits of battery parameters
bms_parameter_limits = { 
                          "temperature" : { "min" : 0, "max": 45 },
                          "soc"         : { "min" : 20, "max": 80 }
                       }

#plug adapter depending upon format requested
def getBatteryParameters(stream_format):
    if stream_format == 'json':
        return getBatteryParametersJson()
    else:
        return None

#check if it is supported stream format
def isSupportedStreamFormat(stream_format):
    if stream_format in allowed_formats:
        return True
    else:
        return False  

#generate json for output stream
def getBatteryParametersJson():
    battery_parameters = {}
    for param in bms_parameter_limits.keys():
        battery_parameters[param] = generateRandomValues(param)
    return battery_parameters

#mock bms data by random number generator between minimum and maximum
def generateRandomValues(param):
    minimum = bms_parameter_limits[param]["min"]
    maximum = bms_parameter_limits[param]["max"]
    return random.randint(minimum,maximum)

#API for end user to get BMS steam
def getBMSStream(stream_length,stream_format):
    if isSupportedStreamFormat(stream_format):
        bms_count = 0
        while (bms_count < stream_length):
            print(getBatteryParameters(stream_format))
            bms_count += 1
    else:
        formats = ' '.join(allowed_formats)
        print("Unsupported Stream Format. Supported Stream Formats are: "+formats)
        return 'UNSUPPORTED_STREAM_FORMAT'
