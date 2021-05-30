import unittest
import BatteryManagementSystem
class test_bms_streaming(unittest.TestCase):
    def test_incorrect_stream_format(self):
        self.assertTrue(BatteryManagementSystem.getBMSStream(stream_length = 100, stream_format = "list") == 'UNSUPPORTED_STREAM_FORMAT")
    def test_bms_stream_in_json_format(self):
        BatteryManagementSystem.getBMSStream(stream_length = 100, stream_format = "json")
    def test_bms_stream_is_json(self):
        self.assertTrue(isinstance(BatteryManagementSystem.getBatteryParameters('json'),dict)) 
      
if __name__ == '__main__':
    unittest.main()
