using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class AccomodationImage
    {
        public int AccomodationImageId { get; set; }
        public string Name { get; set; }
        public string FileType { get; set; }
        public string Extension { get; set; }
        public string UploadedBy { get; set; }
        public DateTime? CreatedOn { get; set; }
        /*
        * Uma propertyimage pode pertencer a um accomodation
         */

        public byte[] Data { get; set; }
        public int AccomodationId { get; set; }
        public Accomodation Accomodation { get; set; }
    }
}
