using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CprDLL
{
    public class CprCheck
    {
        public enum CprError { NoError, FormatError, DateError, Check11Error };
        public bool Check(string cprTxt, out CprError error)
        {
            error = Check11Test(cprTxt);
            if (error != CprError.NoError)
            {
                return false;
            }
            error = CheckDateTime(cprTxt);
            if (error != CprError.NoError)
            {
                return false;
            }
            error = CheckFormat(cprTxt);
            if (error != CprError.NoError)
            {
                return false;
            }
            return true;
        }
        private CprError Check11Test(string cprTxt)
        {
            CprError cprError = CprError.NoError;

            int sum = 0;
            for (int i = 0; i < 3; i++)
            {
                sum += int.Parse(cprTxt.Substring(i, 1)) * (4 - i);
            }
            for (int i = 3; i < 10; i++)
            {
                sum += int.Parse(cprTxt.Substring(i, 1)) * (10 - i);
            }
            if (sum % 11 != 0)
            {
                cprError = CprError.Check11Error;
            }
            return cprError;
        }
        private CprError CheckDateTime(string cprTxt)
        {
            DateTime date;
            string substring = cprTxt.Substring(0, 6);
            bool result = DateTime.TryParseExact(substring, @"ddMMyy", new CultureInfo("en-US"), DateTimeStyles.None, out date);
            if (result) return CprError.NoError;
            return CprError.DateError;
        }
        private CprError CheckFormat(string cprTxt)
        {
            if (cprTxt.Length != 10)
            {
                return CprError.FormatError;
            }
            return CprError.NoError;
        }
    }
}
