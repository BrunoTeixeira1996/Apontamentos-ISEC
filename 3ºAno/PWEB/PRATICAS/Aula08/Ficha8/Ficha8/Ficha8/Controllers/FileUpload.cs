using Ficha8.Data;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Ficha8.Models;
using System.IO;
using Microsoft.AspNetCore.Http;
using Microsoft.EntityFrameworkCore;

namespace Ficha8.Controllers
{
    public class FileUploadController : Controller
    {
        private readonly ApplicationDbContext _context;

        public FileUploadController(ApplicationDbContext context)
        {
            _context = context;
        }

        public IActionResult Index()
        {
            FileUploadViewModel ficheiros = new FileUploadViewModel
            {
                FilesOnDatabases = _context.FilesOnDatabases.ToList(),
                FilesOnFileSystems = _context.FilesOnFileSystems.ToList()
            };
            return View(ficheiros);
        }


        [HttpPost]
        public async Task<IActionResult> UploadToFileSystem(List<IFormFile> files, string description)
        {
            foreach (var file in files)
            {
                var basePath = Path.Combine(Directory.GetCurrentDirectory() + "\\UPLOADS\\");
                bool basePathExists = System.IO.Directory.Exists(basePath);
                if (!basePathExists) Directory.CreateDirectory(basePath);
                var fileName = Path.GetFileNameWithoutExtension(file.FileName);
                var filePath = Path.Combine(basePath, file.FileName);
                var extension = Path.GetExtension(file.FileName);
                if (!System.IO.File.Exists(filePath))
                {
                    // grava no FileSystem
                    using (var stream = new FileStream(filePath, FileMode.Create))
                    {
                        await file.CopyToAsync(stream);
                    }

                    // guarda na base de dados os dados relativos ao ficheiro (sem o conteudo em si)
                    var fileModel = new FilesOnFileSystem
                    {
                        CreatedOn = DateTime.UtcNow,
                        FileType = file.ContentType,
                        Extension = extension,
                        Name = fileName,
                        Description = description,
                        FilePath = filePath
                    };
                    _context.FilesOnFileSystems.Add(fileModel);
                    _context.SaveChanges();
                }
            }
            TempData["Message"] = "File successfully uploaded to File System.";
            return RedirectToAction("Index");
        }

        public async Task<IActionResult> DownloadFileFromFileSystem(int id)
        {
            var file = await _context.FilesOnFileSystems.Where(x => x.Id == id).FirstOrDefaultAsync();
            if (file == null) return null;
            var memory = new MemoryStream();
            using (var stream = new FileStream(file.FilePath, FileMode.Open))
            {
                await stream.CopyToAsync(memory);
            }
            memory.Position = 0;
            return File(memory, file.FileType, file.Name + file.Extension);
        }


        public async Task<IActionResult> DeleteFileFromFileSystem(int id)
        {
            var file = await _context.FilesOnFileSystems.Where(x => x.Id == id).FirstOrDefaultAsync();
            if (file == null) return null;
            if (System.IO.File.Exists(file.FilePath))
            {
                System.IO.File.Delete(file.FilePath);
            }
            _context.FilesOnFileSystems.Remove(file);
            _context.SaveChanges();
            TempData["Message"] = $"Removed {file.Name + file.Extension} successfully from File System.";
            return RedirectToAction("Index");
        }

        [HttpPost]
        public async Task<IActionResult> UploadToDatabase(List<IFormFile> files, string description)
        {
            foreach (var file in files)
            {
                var fileName = Path.GetFileNameWithoutExtension(file.FileName);
                var extension = Path.GetExtension(file.FileName);
                var fileModel = new FilesOnDatabase
                {
                    CreatedOn = DateTime.UtcNow,
                    FileType = file.ContentType,
                    Extension = extension,
                    Name = fileName,
                    Description = description
                };
                using (var dataStream = new MemoryStream())
                {
                    await file.CopyToAsync(dataStream);
                    fileModel.Data = dataStream.ToArray();
                }
                _context.FilesOnDatabases.Add(fileModel);
                _context.SaveChanges();
            }
            TempData["Message"] = "File successfully uploaded to Database";
            return RedirectToAction("Index");
        }

        public async Task<IActionResult> DownloadFileFromDatabase(int id)
        {
            var file = await _context.FilesOnDatabases.Where(x => x.Id == id).FirstOrDefaultAsync();
            if (file == null) return null;
            return File(file.Data, file.FileType, file.Name + file.Extension);
        }


        public async Task<IActionResult> DeleteFileFromDatabase(int id)
        {
            var file = await _context.FilesOnDatabases.Where(x => x.Id == id).FirstOrDefaultAsync();
            _context.FilesOnDatabases.Remove(file);
            _context.SaveChanges();
            TempData["Message"] = $"Removed {file.Name + file.Extension} successfully from Database.";
            return RedirectToAction("Index");
        }
    }
}
