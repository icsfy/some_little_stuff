#coding=utf-8
#!/usr/bin/python
#Filename unzip_baidu.py

from datetime import *
import pdb
import struct
import os
import sys

select_modes = ['danyang','pricevolume','PEG','weekvolume']

class UNPACK_BAIDU_ZIP():
    '''
    Extract downloaded zip file from pan.baidun.com
    Support multi filenams.
    
    synax:
    python unzip_baidu.py pack.zip pack_2.zip
    python unzip_baidu.py d:\temp\pack.zip
    
    if any suggestion, pls contact
    written by lei626@sina.cn
    Jun 28th, 2017  Suzhou, China
    '''
    
    def __init__(self):
        pass
    
    def Unpack(self, zipname):
        
        x = len(zipname)+20
        print('='*x)
        # check file exists or not
        if os.path.exists(zipname):
            print("Extracting file : '%s' "%zipname)
            print('-'*x)
        else:
            print(" No source file : '%s'"%zipname)
            return None
            
        self.spath = os.path.dirname(os.path.abspath(zipname))
        f = open(zipname,'rb')
        
        # check whether this is zip file or not, zip file start with file header
        header = self.__parse_file_header(f.read(0x1E))
        if header is None:
            f.close()
            print(" Not a zip file : '%s'"%zipname)
            return None
        
        # get central directory structure
        # decode file number and offset from end
        cds_tag = struct.pack('L', 0x06054b50)
        f.seek(-100,2)
        block = f.read(100)
        if not cds_tag in block:
            f.close()
            print(" No zip end tag : '%s'"%zipname)
            return None
        
        i = block.index(cds_tag)
        ost = struct.unpack('L', block[i+12:i+16])[0]
        
        f.seek(i-100, 2)   # move to start of 'end of central directory record' 
        x = f.tell()
        
        f.seek(-ost,1)  # move to start of 'central directory structure record'
        y = f.tell()    # where it is end of files
        
        # read central structure records, get all files list
        self.files = []
        while f.tell() < x:
            header = self.__parse_cds_header(f.read(0x2E))
            fname = self.__parse_file_name(f.read(header['file_name_len']))
            f.read(header['extra_field_len'])                       # skip extra field
            if fname is not None : self.files.append(fname)
        
        print("%3d folder(s) and file(s) found..."%len(self.files))
        #for k in range(len(self.files)):
        #    print('%2d  %s'%(k,self.files[k]))
        # back to start and unpack
        f.seek(0,0)
        j = 0
        while f.tell() < y:
            header = self.__parse_file_header(f.read(0x1E))
            fname = self.__parse_file_name(f.read(header['file_name_len']))
            
            extra = f.read(header['extra_field_len'])
            fs = header['compressed_size']
            j += 1
            if fs == 0:
                print("%3d   Writing file : '%s' "%(j,fname), sep='', end='', flush=True)
                self.__build_folder(fname)
                print(' ok!')
            else:
                # if file size is wrong, read until to next tag
                print("%3d   Writing file : '%s' "%(j,fname), sep='', end='', flush=True)
                bsize = 1024*1024*50
                fo = open(fname, 'wb')
                c = 0
                print('   ',end='')
                while True:
                    c += 1
                    block = f.read(bsize)
                    x = self.__write_file(fo, block)
                    print('\b'*3,'%3d'%c, sep='', end = '',flush=True)
                    if x < 0 or f.tell()>y : break
                print('\b'*3,'   ','\b'*3,sep='',end='',flush=True)
                fo.close()
                if x<0 : f.seek(x,1)
                print(' ok!')
        f.close()
        print('\nDone!\n')
    
    def __write_file(self, fo, block):
    
        # if find file header tag, then try to read filename, if filename
        # in files list, it should be another file
        # otherwise, this block blongs one file
        
        tag = struct.pack('L', 0x04034b50)
        # contents before two tags blongs to file_output
        i = 0
        while block.find(tag,i) >= 0:
            i = block.find(tag,i)
            header = self.__parse_file_header(block[i:i+0x1E])
            fname = self.__parse_file_name(block[i+0x1E:i+0x1E+header['file_name_len']])
            if fname is not None and fname in self.files:
                fo.write(block[:i])
                return i - len(block)
            i += 4
        else:
            fo.write(block)
            return 0
    
    def __build_folder(self, spath):
        if not os.path.exists(spath):
            os.makedirs(spath)
    
    def __parse_file_name(self, block):
        try:
            fname = block.decode('gbk')
            fname = os.path.join(self.spath, fname.replace('/','\\'))
            return fname
        except:
            return None
            
            
    def __parse_file_header(self, header):
        if len(header) != 0x1E : return None    # 0x1E=30
        h = {}
        i2 = struct.Struct('H')
        i4 = struct.Struct('L')
        h['file_tag'] = i4.unpack_from(header[0:4])[0]
        if h['file_tag'] != 0x04034b50 : return None
        h['extract_version'] = i2.unpack_from(header[4:6])[0]
        h['bit_flag'] = i2.unpack_from(header[6:8])[0]
        h['method'] = i2.unpack_from(header[8:10])[0]
        h['last_mod_time'] = i2.unpack_from(header[10:12])[0]
        h['last_mod_date'] = i2.unpack_from(header[12:14])[0]
        h['crc32'] = i4.unpack_from(header[14:18])[0]
        h['compressed_size'] = i4.unpack_from(header[18:22])[0]
        h['uncompressed_size'] = i4.unpack_from(header[22:26])[0]
        h['file_name_len'] = i2.unpack_from(header[26:28])[0]
        h['extra_field_len'] = i2.unpack_from(header[28:30])[0]
        return h
        
    def __parse_cds_header(self, header):
        if len(header) != 0x2E : return None    # 0x2E=46
        h = {}
        i2 = struct.Struct('H')
        i4 = struct.Struct('L')
        h['cds_tag'] = i4.unpack_from(header[0:4])[0]
        if h['cds_tag'] != 0x02014b50 : return None
        h['made_version'] = i2.unpack_from(header[4:6])[0]
        h['extract_version'] = i2.unpack_from(header[6:8])[0]
        h['bit_flag'] = i2.unpack_from(header[8:10])[0]
        h['method'] = i2.unpack_from(header[10:12])[0]
        h['last_mod_time'] = i2.unpack_from(header[12:14])[0]
        h['last_mod_date'] = i2.unpack_from(header[14:16])[0]
        h['crc32'] = i4.unpack_from(header[16:20])[0]
        h['compressed_size'] = i4.unpack_from(header[20:24])[0]
        h['uncompressed_size'] = i4.unpack_from(header[24:28])[0]
        h['file_name_len'] = i2.unpack_from(header[28:30])[0]
        h['extra_field_len'] = i2.unpack_from(header[30:32])[0]
        h['file_comment_len'] = i2.unpack_from(header[32:34])[0]
        h['disk_start_no'] = i2.unpack_from(header[34:36])[0]
        h['internal_file_attributes'] = i2.unpack_from(header[36:38])[0]
        h['external_file_attributes'] = i4.unpack_from(header[38:42])[0]
        h['relative_ost'] = i2.unpack_from(header[42:46])[0]
        return h
        
if __name__ == '__main__':
    print()
    print('          *********************************************************')
    print('          *   Only used to extract zip file from pan.baidu.com!   *')
    print('          *********************************************************')

    starttime = datetime.now()
    print('\nStart:  %s'%starttime.strftime('%H:%M:%S'))
    print()

    if len(sys.argv) < 2:
        print('No input of unpack zip file name! \nExit!')
        sys.exit()
    fnames = sys.argv[1:]
    ubz = UNPACK_BAIDU_ZIP()
    for fname in fnames:
        ubz.Unpack(fname)
        print()
    endtime=datetime.now()
    usetime=endtime-starttime
    usetime=timedelta(usetime.days,usetime.seconds,0)
    print('\nTotal used time:')
    print('Start:  %s'%starttime.strftime('%H:%M:%S'))
    print('End  :  %s'%endtime.strftime('%H:%M:%S'))
    print('Used :  ','0'*(8-len(str(usetime))),str(usetime),sep='')