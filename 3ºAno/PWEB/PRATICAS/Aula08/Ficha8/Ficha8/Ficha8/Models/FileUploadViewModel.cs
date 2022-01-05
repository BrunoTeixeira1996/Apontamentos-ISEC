using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha8.Models
{
    public class FileUploadViewModel
    {
        public List<FilesOnFileSystem> FilesOnFileSystems { get; set; }
        public List<FilesOnDatabase> FilesOnDatabases { get; set; }

    }
}
