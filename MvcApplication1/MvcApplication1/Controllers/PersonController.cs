using MvcApplication1.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Http;
using System.Web.Mvc;

namespace MvcApplication1.Controllers
{
    public class PersonController : Controller
    {
        //
        // GET: /Person/
        Person[] persons = new Person[]
        {
            new Person{Id = 1,Name = "jim",Age = 20,City = "bei jing"},
            new Person{Id = 2,Name = "lili",Age = 23,City = "shang hai"},
            new Person{Id = 3,Name = "alan",Age = 26,City = "tian jin"}
        };

        public IEnumerable<Person> GetAllPersons()
        {
            return persons;
        }

        public Person getPersonById(int id)
        {
            var person = persons.FirstOrDefault((p) => p.Id == id);
            if (person == null)
            {
                throw new HttpResponseException(HttpStatusCode.NotFound);
            }
            return person;
        }

        public IEnumerable<Person> GetPersonsByCity(string city)
        {
            return persons.Where((p) => string.Equals(p.City, city,
                StringComparison.OrdinalIgnoreCase));
        }
       //url 路径对应Person/person1
        public ActionResult person1()
        {
            return Json(persons,JsonRequestBehavior.AllowGet);
        }
        //url 路径对应Person/person2/1
        public ActionResult person2(int id)
        {
            return Json(persons.FirstOrDefault((p) => p.Id == id), JsonRequestBehavior.AllowGet);
        }
    }
}
